//验证用户名   
function checkUserName() {
	const username = document.getElementById('userName');
	const errname = document.getElementById('nameErr');
	//var pattern = /^\w{3,}$/; //用户名格式正则表达式：用户名要至少三位 
	if (username.value.length == 0) {
		errname.innerHTML = "用户名不能为空"
		username.style.borderColor = 'red'
		errname.style.color = 'red'
		return false;
	}
	if (username.value.length <= 1) {
		errname.innerHTML = "用户名不合规范，至少三位"
		username.style.borderColor = 'red'
		errname.style.color = 'red'
		return false;
	} else {
		errname.innerHTML = "该昵称可用"
		username.style.borderColor = 'lime'
		errname.style.color = 'green'
		return true;
	}
}

//验证密码   
function checkPassword() {
	const userpasswd = document.getElementById('userPasword');
	const errPasswd = document.getElementById('passwordErr');
	const pattern = /^\w{4,12}$/; //密码要在4-12位
	if (userpasswd.value.length == 0) {
		errPasswd.innerHTML = "密码不能为空"
		userpasswd.style.borderColor = 'red'
		errPasswd.style.color = 'red'
		return false;
	}
	if (!pattern.test(userpasswd.value)) {
		errPasswd.innerHTML = "密码不合规范，因在4-12位之间"
		userpasswd.style.borderColor = 'red'
		errPasswd.style.color = 'red'
		return false;
	} else {
		errPasswd.innerHTML = "密码符合"
		userpasswd.style.borderColor = 'lime'
		errPasswd.style.color = 'green'
		return true;
	}
}

//验证手机号 
function checkPhone() {
	const codediv = document.getElementById('codediv');
	codediv.style.display = 'block';
	const userphone = document.getElementById('userPhone');
	const phonrErr = document.getElementById('phoneErr');
	const pattern = /^1[34578]\d{9}$/; //验证手机号正则表达式
	if (!pattern.test(userphone.value)) {
		phonrErr.innerHTML = "手机号码不合规范"
		userphone.style.borderColor = 'red'
		phonrErr.style.color = 'red'
		return false;
	} else {
		phonrErr.innerHTML = "手机号格式正确"
		userphone.style.borderColor = 'lime'
		phonrErr.style.color = 'green'
		return true;
	}
}

//发送验证码
let clock = '';
let nums = 60;
let btn;
let xmlhttp;
function codeclick(thisBtn) {
	 //一秒执行一次
	let codediv = document.getElementById('codediv');
	let codeErr = document.getElementById('codeErr');
	const name = checkUserName();
	const password = checkPassword();
	const phone = checkPhone();
	const VerifyPhone = document.getElementById('userPhone');
	if (name && password && phone) {
		SendPhoneVerify(VerifyPhone.value)
		.then((res)=>{
			if(VerifyPhone.value == res){
				codeErr.innerHTML = "该手机号已注册";
				codeErr.style.color = 'red'
				console.log("已注册")
			}
			else{
				fetch('/sendSmsVerify?_w_phone='+VerifyPhone.value);
				codediv.style.display = 'block';
				btn = thisBtn;
				btn.disabled = true; //按钮不可点击
				btn.value = nums+'秒后可重新获取';
				clock = setInterval(doLoop,1000);
				codeErr.innerHTML = "短信已发送，请注意查收";
				codeErr.style.color = 'green'
				console.log("没有注册")
			}
		})
	}
}

async function SendPhoneVerify(VerifyPhone) {
	const res = await fetch('/sendPhoneVerify?_w_phone='+VerifyPhone) ;// getToken -> expires_in
	const data = await res.json();
	return data.phone;
}

function doLoop()
{
	nums--;
	if(nums>0){
		btn.value = nums+'秒后可重新获取';
	}else{
		clearInterval(clock);//清除js定时器
		btn.disabled = false;
		btn.value = '获取短信验证码';
		nums =60;
	}
}
function callback() {
	if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
		//var rt = xmlHttpRequest.responseText;
		//alert(xmlHttpRequest.responseText);
		// do something with rt
	}
}
function lableclick()
{
	const clause = document.getElementById('clause');
	const imgupdown = document.getElementById('imgupdown');
	if(clause.style.display=='none'){
		clause.style.display ='block';
		imgupdown.src='img/down.png'
	}
	else{
		a=0;
		clause.style.display ='none';
		imgupdown.src='img/up.png'
	}
}

//验证验证码
function codeverify(){
	//昵称
	const username = document.getElementById('userName');
	//密码
	const userpasswd = document.getElementById('userPasword');
	//手机号
	const userphone = document.getElementById('userPhone');
	//验证码
	const usercode = document.getElementById('userCode')
	//提示
	const codeErr = document.getElementById('codeErr');
	//获取注册页面验证码，与数据库作对比
	SendVerify(userphone.value)
	.then((res)=>{
		if(res == usercode.value){
			//若正确 根据相关信息生成fdog号转向新的界面
			codeErr.innerHTML = "注册成功";
			codeErr.style.color = 'green'
			//window.location.href()
			console.log("相同")
			window.location.href = "/registersuccess"
		}
		else{
			//若验证码错误则提示错误
			codeErr.innerHTML = "验证码错误";
			codeErr.style.color = 'red'
			console.log("不同")			
		}
	})

	//若正确 根据相关信息生成fdog号转向新的界面
	//window.open('registersuccess.html'
}

async function SendVerify(VerifyPhone){
		const res = await fetch('/sendVerify?_w_phone='+VerifyPhone) ;// getToken -> expires_in
	const data = await res.json();
	return data.code;
}

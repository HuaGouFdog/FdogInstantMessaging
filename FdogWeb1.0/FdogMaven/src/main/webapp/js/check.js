//验证用户名   
function checkUserName() {
	var username = document.getElementById('userName');
	var errname = document.getElementById('nameErr');
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
	var userpasswd = document.getElementById('userPasword');
	var errPasswd = document.getElementById('passwordErr');
	var pattern = /^\w{4,12}$/; //密码要在4-12位 
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
	var codediv = document.getElementById('codediv');
	codediv.style.display = 'block';
	var userphone = document.getElementById('userPhone');
	var phonrErr = document.getElementById('phoneErr');
	var pattern = /^1[34578]\d{9}$/; //验证手机号正则表达式 
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
//验证发送短信验证码
var clock = '';
var nums = 60;
var btn;
var xmlhttp;
function codeclick(thisBtn) {
	var name = checkUserName();
	var password = checkPassword();
	var phone = checkPhone();
	if (name && password && phone) {
		//调用后台发送短信
		if (window.XMLHttpRequest)
		  {// code for IE7+, Firefox, Chrome, Opera, Safari
		  xmlhttp=new XMLHttpRequest();
		  }
		else
		  {// code for IE6, IE5
		  xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
		  }
		xmlhttp.open("POST","AuthCode?phone=18082069891",true);
		xmlhttp.setRequestHeader("Content-type","application/x-www-form-urlencoded");
		
		//xmlhttp.send("fname=Bill&lname=Gates");
		xmlhttp.send();
		//this.form.action='authCode';
		//this.form.submit();
		var codediv = document.getElementById('codediv');
		codediv.style.display = 'block';
		btn = thisBtn;
		btn.disabled = true; //按钮不可点击
		btn.value = nums+'秒后可重新获取';
		clock = setInterval(doLoop,1000); //一秒执行一次
		var codeErr = document.getElementById('codeErr');
		codeErr.innerHTML = "短信已发送，请注意查收";
		codeErr.style.color = 'green'
	}
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
	var clause = document.getElementById('clause');
	var imgupdown = document.getElementById('imgupdown');
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

<%@page contentType="text/html;charset=utf-8"%>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<title>Fdog注册</title>
		<meta name="viewport" content="width=device-width, initial-scale=1.0, minimum-scale=0.5, maximum-scale=2.0, user-scalable=yes" /> 
		<link rel="stylesheet" href="css/fdog.css">
		<link rel="shortcut icon" href="img/favicon1.ico" type="image/x-icon" />
		<link rel="apple-touch-icon" href="img/fdogicon.png">
	</head>
	<body>
		<script src="js/backv.js"></script>
		<script src="js/check.js"></script>
		<div class="fdogback">
			<a href="http://127.0.0.1:8848/newfdog/index_3.html">
				<img id="imgicon_1" src="img/mainicon.png" />
			</a>
			<img src="img/background02.png" id="backimg" style="height: 100%;" />
		</div>
		<div class="fdogtext">
			<div class="fdogtext_1">
				<a href="http://127.0.0.1:8848/newfdog/index_3.html">
					<img id="imgicon_2" src="img/mainicon.png" />
				</a>
				<ul id = "mul">
					<li style="float: right; list-style: none; margin-right: 30px;"><a href="#" style="text-decoration: none; color: gray;">意见反馈</a></li>
					<li style="float: right; list-style: none; margin-right: 30px;"><a href="/FdogMaven/download.html" style="text-decoration: none; color: gray;">下载Fdog</a></li>
					<li style="float: right; list-style: none; margin-right: 30px;"><a href="https://www.fdogcsdn.cn" style="text-decoration: none; color: gray;">首页</a></li>
				</ul>
			</div>
			<div class="fdogtext_2">
				<div id ="mh1">
					<span style="font-size: 48px;">欢迎注册Fdog</span>
				</div>
				<div id ="mh2">
					<span style="font-size: 30px;">每一天，乐在沟通。</span>
				</div>
				<form action="FdogMaven" name="form" method="post">
					<div style="height: 30px; "></div>
					<input tyle="text" id="userName" name="username" placeholder="昵称" onBlur="checkUserName()" oninput="checkUserName()" 
					value='<%=request.getParameter("username")==null?"":request.getParameter("username")%>'/>
					<div id="um">
						<span class="default" id="nameErr" style="color: white;"></span>
					</div>
					<input type="password" id="userPasword" name="password" placeholder="密码" onBlur="checkPassword()" oninput="checkPassword()" 
					value='<%=request.getParameter("password")==null?"":request.getParameter("password")%>'/>
					<div id="pw">
						<span class="default" id="passwordErr" style="color: white;"></span>
					</div>
					<span>
						<select name="comboxphone" id="comboxphone">
							<option>中国+86</option>
							<option>中国香港特别行政区+852</option>
							<option>中国澳门特别行政区+853</option>
							<option>中国台湾地区+886</option>
						</select>
						<input type="text" id="userPhone" name="phone" placeholder="手机号" onBlur="checkPhone()" oninput="checkPhone()" 
						value='<%=request.getParameter("phone")==null?"":request.getParameter("phone")%>'/>
					</span>
					<div style="height: 50px; width: 490px;  margin: 0 auto; text-align: left; color: gray;">
						<span>可通过该手机号找回密码&nbsp;</span>
						<span class="default" id="phoneErr" style="color: white;"></span>
					</div>
					<div id="codediv" style=" height: 100px; width:100%;">
						<input tyle="text" id="code" name="verificationcode" placeholder="验证码" />
						<input type="button" id="codebutton" value="获取短信验证码" onclick="codeclick(this)"/>
						<div style="height: 50px; width: 490px;  margin: 0 auto; text-align: left; color: gray;">
							<span class="default" id="codeErr" style="color: white;"></span>
						</div>
					</div>
					<input type="submit" id="up" class="register" value="立即注册" onclick="this.form.submit();"/>
					<div style="height: 30px;width: 490px;  margin: 0 auto; text-align: left; color: gray;">
						<p><input type="checkbox" checked="checked" />
						我已阅读并同意相关服务条款和隐私政策 
						<img id="imgupdown" style="height: 16px;" src="img/up.png" onclick="lableclick()"/> 
						</p>
					</div>
					<div id ="clause" style=" height: 100px; width: 480px; text-align: left; margin:  0 auto; display: none;">
						<a href="#"style="text-decoration: none; color: cornflowerblue;" >《Fdog号码规则》</a><br>
						<a href="#"style="text-decoration: none; color: cornflowerblue;" >《隐私协议》</a><br>
						<a href="#" style="text-decoration: none; color: cornflowerblue;">《Fdog注册使用协议》</a>
					</div>
				</form>
			</div>
			<div class="fdogtext_3">
				Copyright © 2021.花狗Fdog All rights reserved.
				<br class="brcopy">
				<a href="https://beian.miit.gov.cn/" style="text-decoration: none; color: black; color: gray;">蒙ICP备2021000567号</a>
			</div>
		</div>
	</body>
</html>

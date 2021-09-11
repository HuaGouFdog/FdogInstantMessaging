<%@page contentType="text/html;charset=utf-8"%>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Fdog注册</title>
		<link rel="shortcut icon" href="img/favicon1.ico" type="image/x-icon" />
		<link rel="apple-touch-icon" href="img/fdogicon.png">
	</head>
	<body style="margin: 0;">
		<%
		String Maccount = (String)request.getAttribute("account");  
		String Mphone = (String)request.getAttribute("phone");  
		%>
		<div style=" background-color:rgba(0,0,0,0.6); height: 65px; font-size: 20px; ">
			<img src="img/mainicon.png" style="margin-left: 30px; margin-top: 5px; height: 60px; float: left;" />
		</div>
		<div>
			<div style="float: left; width: 120px;">
				<img src="img/succeed.png" style="width: 90px;" />
			</div>
			<div>
				<span style="font-size: 30px;">申请成功，您获得号码：</span>
				<br>
				<input style="font-size: 25px; height: 30px;" name="account" value='<%=Maccount%>'/>
				<!-- <span style="font-size: 40px;">2506897252</span> -->
			</div>
			<br>
			<div style="float: left;">
				<img src="img/suo.png" style="width: 25px;" />
			</div>
			<div>
				<span style="font-size: 20px;">你可以通过手机号码<input style="font-size: 25px; border: 0px;width: 250px;" name="account" value='<%=Mphone%>'/> 快速找回密码</span>
			</div>
			<br>
			<div style="float: left;">
				<img src="img/phone.png" style="width: 25px;" />
			</div>
			<div>
				<span style="font-size: 20px;">你可以通过手机号码<input style="font-size: 25px; border: 0px;width: 250px;" name="account" value='<%=Mphone%>'/> 作为辅助账号登录Fdog</span>
			</div>
			<div style="height: 50px;"></div>
			<button style="height: 40px; width: 200px;">登录</button>
			<button style="height: 40px; width: 200px;"><a href="/FdogMaven/download.html">下载Fdog</a></button>
		</div>
	</body>
</html>

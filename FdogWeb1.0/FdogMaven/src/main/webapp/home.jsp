<%@page contentType="text/html;charset=utf-8"%>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<link rel="stylesheet" href="FdogMaven/css/index_1.css">
		<link rel="shortcut icon" href="FdogMaven/img/favicon1.ico" type="image/x-icon" />
		<link rel="apple-touch-icon" href="FdogMaven/img/fdogicon.png">
		<title>I'm Fdog - 每一天，乐在沟通</title>
		<script src="http://libs.baidu.com/jquery/2.0.0/jquery.min.js"></script>
		<script>
			$(function(){
			　　function n(n,e,t){
			   　　return n.getAttribute(e)||t
			   }
			   function e(n){
			   　　return document.getElementsByTagName(n)
			   }
			   function t(){
			   　　var t=e("script"),o=t.length,i=t[o-1];
				  return{l:o,z:n(i,"zIndex",-1),o:n(i,"opacity",.8),c:n(i,"color","0,0,0"),n:n(i,"count",150)}
			   }
			   function o(){
			   　　a=m.width=window.innerWidth||document.documentElement.clientWidth||document.body.clientWidth,
				  c=m.height=window.innerHeight||document.documentElement.clientHeight||document.body.clientHeight
			   }
			   function i(){
			   　　r.clearRect(0,0,a,c);
				  var n,e,t,o,m,l;
				  s.forEach(function(i,x){
				  　　for(i.x+=i.xa,i.y+=i.ya,i.xa*=i.x>a||i.x<0?-1:1,i.ya*=i.y>c||i.y<0?-1:1,r.fillRect(i.x-.5,i.y-.5,1,1),e=x+1;e<u.length;e++)n=u[e],
					 　　null!==n.x&&null!==n.y&&(o=i.x-n.x,m=i.y-n.y,
					 　　l=o*o+m*m,l<n.max&&(n===y&&l>=n.max/2&&(i.x-=.03*o,i.y-=.03*m),
						t=(n.max-l)/n.max,r.beginPath(),r.lineWidth=t/2,r.strokeStyle="rgba("+d.c+","+(t+.2)+")",r.moveTo(i.x,i.y),r.lineTo(n.x,n.y),r.stroke()))
				  }),
				  x(i)
		　　　　}
		　　　　var a,c,u,m=document.createElement("canvas"),d=t(),l="c_n"+d.l,r=m.getContext("2d"),
			   x=window.requestAnimationFrame||window.webkitRequestAnimationFrame||window.mozRequestAnimationFrame||window.oRequestAnimationFrame||window.msRequestAnimationFrame||
		　　　　function(n){
		　　　　　　window.setTimeout(n,1e3/45)
		　　　　},
		　　　　w=Math.random,y={x:null,y:null,max:2e4};m.id=l,m.style.cssText="position:fixed;top:0;left:0;z-index:"+d.z+";opacity:"+d.o,e("body")[0].appendChild(m),o(),window.onresize=o,
		　　　　window.onmousemove=function(n){
		　　　　　　n=n||window.event,y.x=n.clientX,y.y=n.clientY
		　　　　},
		　　　　window.onmouseout=function(){
		　　　　　　y.x=null,y.y=null
		　　　　};
			　 for(var s=[],f=0;d.n>f;f++){
				　　var h=w()*a,g=w()*c,v=2*w()-1,p=2*w()-1;s.push({x:h,y:g,xa:v,ya:p,max:6e3})
			   }
			　　u=s.concat([y]),
			　　setTimeout(function(){i()},100)
			});
		</script>
		<script src="https://eqcn.ajz.miesnfu.com/wp-content/plugins/wp-3d-pony/live2dw/lib/L2Dwidget.min.js"></script>
		<script>
			L2Dwidget.init({ 
				"model": { "jsonPath":"https://unpkg.com/live2d-widget-model-shizuku@1.0.5/assets/shizuku.model.json", "scale": 1, "hHeadPos":0.5, "vHeadPos":0.618 },
				"display": { "position": "right", "width": 100, "height": 200, "hOffset": 420, "vOffset": 120 }, 
				"mobile": { "show": true, "scale": 0.5 },
				"react": { "opacityDefault": 0.7, "opacityOnHover": 0.2 } 
				});
		</script>
		<!--
			其他可选的模型： 
				小帅哥： https://unpkg.com/live2d-widget-model-chitose@1.0.5/assets/chitose.model.json
				萌娘：https://unpkg.com/live2d-widget-model-shizuku@1.0.5/assets/shizuku.model.json 
				小可爱（女）：https://unpkg.com/live2d-widget-model-koharu@1.0.5/assets/koharu.model.json 
				小可爱（男）：https://unpkg.com/live2d-widget-model-haruto@1.0.5/assets/haruto.model.json
				初音：https://unpkg.com/live2d-widget-model-miku@1.0.5/assets/miku.model.json 
		-->
	</head>
	<body>
		<div style=" background-color:rgba(0,0,0,0.6); height: 65px; font-size: 20px; ">
			<img src="FdogMaven/img/mainicon.png"  style="margin-left: 30px; margin-top: 5px; height: 60px; float: left;"/>
			<ul id = "mul" style="float:right;margin-top: 1;margin-bottom: 0; padding: 0;">
				<li style="float: right; list-style: none; margin-right: 70px;"><a href="#" style="text-decoration: none; color: azure;">意见反馈</a></li>
				<li style="float: right; list-style: none; margin-right: 70px;"><a href="/FdogMaven/index.jsp" style="text-decoration: none; color: azure;">注册Fdog</a></li>
				<li style="float: right; list-style: none; margin-right: 70px;"><a href="/FdogMaven/download.html" style="text-decoration: none; color: azure;">下载Fdog</a></li>
				<li style="float: right; list-style: none; margin-right: 70px;"><a href="https://www.fdogcsdn.cn" style="text-decoration: none; color: azure;">首页</a></li>
			</ul>
		</div>
		<div style="background-color: rgba(255,255,255,0.7); height: 670px; width: 1100px; margin: 40px auto; border-radius: 20px; 
		text-align: left; font-size: 20px; padding-left: 40px;padding-right: 40px; padding-top: 50px">
			<div style="height: 10px;"></div>
			江湖人称花狗Fdog，读于泰州职业技术学院，软件技术专业，积极入党分子，校学生会干部。
			<div style="height: 20px;"></div>
			私下自学PS，C语言，C++语言，Qt，数据结构与算法，数据库，学校里，学习过java语言，html，以及javaweb。 
			<div style="height: 20px;"></div>
			学校曾获得：
			<div style="height: 20px;"></div>
			优秀干事，三好学生，优秀团员，一等奖学金，国家励志奖学金。
			<div style="height: 20px;"></div>
			网络曾获得：
			<div style="height: 20px;"></div>
			华为云·云享专家，CSDN博客专家，CSDN2020年度博客之星第68名，CSDN2020年度优秀创作者。
			<div style="height: 20px;"></div>
			学习的同时本人也喜欢写一些技术博客：
			<a href="https://blog.csdn.net/Fdog_" >我的技术博客</a>
			，也曾学习并使用Github:
			<a href="https://github.com/FdogMain" >我的Github</a>
			。
			<div style="height: 20px;"></div>
			讲尽千言万语，不如拿出一个项目实在，Fdog是我仿照某聊天软件所开发，期间运用到的技术包括使用ps进行ui制作，qt，
			<div style="height: 20px;"></div>
			vs进行pc端开发，as进行移动端开发(没动呢)，html进行前端页面开发，js，javaweb后台开发并部署于服务器，使用mysql数据库
			<div style="height: 20px;"></div>
			等多项语言技术开发的实时通信软件，同时本软件仅供学习使用，帮助新手了解开发路线，请切勿用于商业用途。
			<div style="height: 20px;"></div>
			漫漫代码路，不敢说学到很多，但一定不少，就把这个fdog作为我的毕设吧。
			<div style="height: 20px;"></div>
			邮箱：2506897252@qq.com
		</div>
		<div class="fdogtext_3" style="color: white;" >
			Copyright © 2021.花狗Fdog All rights reserved.
			<a href="https://beian.miit.gov.cn/" style="text-decoration: none; color: black; color: white;">蒙ICP备2021000567号</a>
		</div>
	</body>
</html>

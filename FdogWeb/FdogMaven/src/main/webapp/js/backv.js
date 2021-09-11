window.onload = init;
var n = 1; //图片标记数
var dingshi; //让图片动的定时器
function init() {
	dingshi = window.setInterval("tupian()", 5000);
}
//更换图片
function tupian() {
	var obj = document.getElementById("backimg");
	n++;
	if (n >= 5) {
		n = 1;
	}
	obj.src = "img/background0" + n + ".png";
}

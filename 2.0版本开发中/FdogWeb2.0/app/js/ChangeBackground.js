window.onload = init;
let n = 1; //图片标记数
let time; //让图片动的定时器
function init() {
	time = window.setInterval("changebackground()", 5000);
}
//更换图片
function changebackground() {
	const obj = document.getElementById("backimg");
	n++;
	if (n >= 5) {
		n = 1;
	}
	obj.src = "img/background0" + n + ".png";
}

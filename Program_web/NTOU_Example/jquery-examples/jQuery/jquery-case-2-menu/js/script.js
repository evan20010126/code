$(function(){
	// 滑鼠移入#navi下一層的li元素
	$("#navi").children("li").hover(function(){
		// 顯示下層選單
		$(this).children("ul").stop().slideToggle(100);
	});
});
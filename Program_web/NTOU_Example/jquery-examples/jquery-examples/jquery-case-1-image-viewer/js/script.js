$(function(){
	// 點按小圖時 
	$("a").click(function(){
		// 將a元素的href屬性值傳給大圖預覽器的src屬性
		$("figure img").attr("src", $(this).attr("href"));
	
		return false;	
	});
});

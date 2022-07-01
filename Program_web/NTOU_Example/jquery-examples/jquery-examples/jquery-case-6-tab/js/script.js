$(function(){
	//隱藏tab1以外的內容
	$('#contents div[id != "tab1"]').hide();
	
	// 點選頁籤
	$("a").click(function(){
		// 先將所有內容設為隱藏不顯示
		$("#contents div").hide();

		// 顯示出選擇頁籤的對應內容
		$($(this).attr("href")).show();
		
		// 移除目前的current類別
		$(".current").removeClass("current");
		
		// 在目前所選頁籤本身加上current類別
		$(this).addClass("current");

		return false;
	});
});
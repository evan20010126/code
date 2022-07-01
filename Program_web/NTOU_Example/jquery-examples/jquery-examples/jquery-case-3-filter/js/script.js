$(function(){
	// 按下按鈕
	$("button").click(function(){
		// 取得value屬性值
		var target = $(this).attr("value");

		// 比對所有li元素
		$("#list li").each(function(){
			// 將所有li元素隱藏不顯示
			$(this).animate({"opacity" : 0}, 300, function(){
				$(this).hide();

				// 比對是否符合篩選條件
				if($(this).hasClass(target) || target == "all"){
					// 顯示符合篩選條件的元素
					$(this).show();
					$(this).animate({"opacity" : 1}, 300);
				}
			});
		});
	});
});

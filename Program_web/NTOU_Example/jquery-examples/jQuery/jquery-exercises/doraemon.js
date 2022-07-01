function Doraemon(audioObject, playButton, accessoryImg, msgDiv) {
	
	this.audioObject = audioObject;
	this.playButton = playButton;
	this.accessoryImg = accessoryImg;
	this.msgDiv = msgDiv;
	
	var accessoryString = "任意門 時光機 竹蜻蜓 時光布 記憶麵包 縮小燈 翻譯蒟蒻 如果電話亭 穿透環 更衣照相機";
	var accessoryNames = [];
	var selectedAccessory = -1;
	
	this.start = function () {
		accessoryNames = accessoryString.split(" ");				
		playButton.addEventListener("click", this.play, false);
		audioObject.addEventListener("ended", this.showAccessory, false);
	}; 		

	this.play = function () {
		accessoryImg.src = "blank.png";
		msgDiv.innerHTML = "";
		selectedAccessory = Math.floor(Math.random() * accessoryNames.length);
		console.log("selectedAccessory: " + selectedAccessory);
		var sound = document.getElementById("sound");
		sound.play();
	};
	
	this.showAccessory = function () {
		var picFile = "";
		if (selectedAccessory < 9)
			picFile = '0' + (selectedAccessory + 1) + ".png";
		else
			picFile = "" + (selectedAccessory + 1) + ".png";

		accessoryImg.src = picFile;
		$("#"+accessoryImg.id).hide();
		$("#"+accessoryImg.id).fadeIn(1500);
		msgDiv.innerHTML = "您抽到" + 　accessoryNames[selectedAccessory] + "!";
	};
}
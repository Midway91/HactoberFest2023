var ps1=new Image ();
var ps2=new Image();
var mati = new Image();
var bg= new Image();
var tg= new Image();
var title = new Image();
var btnulang = new Image();

var point = new Audio();
var death = new Audio();
var tap = new Audio();
var rik = new Audio();
var wosh = new Audio();


rik.src = "sound/bigbrother_fly.mp3"
point.src ="sound/point.mp3";
death.src ="sound/die.mp3";
tap.src ="sound/mulai.mp3";
wosh.src="sound/woosh.mp3";



ps1.src="img/chr1.png";
ps2.src="img/chr2.png";
mati.src="img/mati.png";
bg.src="img/bg.png";
tg.src="img/tiang.png";
title.src="icon.png";
btnulang.src="img/ulang.png";

function start(){
	var canvas = document.getElementById("canvas");
	var ctx = canvas.getContext("2d");

	canvas.width=canvas.scrollWidth;
	canvas.height=canvas.scrollHeight;

	var cw = canvas.width;
	var ch = canvas.height;
	
	var bgX=0,mulai=false,z=180;
	function splash (){
		ctx.clearRect(0,0,cw,ch);
		ctx.drawImage(bg,bgX-=2,0);
		
		if(bgX==-12584){
			bgX=0;
			}
		ctx.fillStyle="#000000";
		ctx.font="Bold 12px courier";
		ctx.fillText("KLIK UNTUK MUALI",125,650);
		
		ctx.drawImage(title,-23,67);
		ctx.drawImage(ps1,100,z+=2);
		
		if(z>=330){
			z=280;
			}
		}
	var insplash = setInterval (splash,30);
	document.addEventListener("click", function (event){
		if(mulai==false){
			mulai=true;
			clearInterval(insplash);
			var hiro = new Audio();
			hiro.src="sound/hiro.mp3";
			hiro.loop=true;
			hiro.play();
			game();
			}
		});
	function game(){
		function background(){
			this.x=0;
			this.render=function (){
				ctx.drawImage(bg,this.x--,0);
				
				if(this.x==633){
					hiro.play();
					this.x=0;
				}
					
			}
		}
		var latar = new background();
		var ganti=false;
		function Player (){
				this.x=100;this.y=350;this.w=100,this.h=100,this.i=0;
				this.render=function (){
				if(ganti){
					rik.play();
					ctx.drawImage(ps2,this.x,this.y+=5);
					this.i++;
				if(this.i==5){
					wosh.play();
					ganti=false;
					this.i=0;
					}
				}else{
						ctx.drawImage(ps1,this.x,this.y+=5);
						}
				}
			}//end player

			var player = new Player ();
			var tiang = [];
			maketiang();
			
			function maketiang(){
				var x=400,y=0,w=50,h=500;
				var acak=Math.floor(Math.random()*250);
				tiang.push({"x":x,"y":y-acak,"w":w,"h":h})
			}
			var hitung=0;
			function selesai(tes){
				btnulang=tes;
				death.play();
				clearInterval(interval);
				ctx.clearRect(0,0,cw,ch);
				latar.render();
				rendertiang();
				ctx.drawImage(mati,player.x, player.y);
				ctx.font="Bold 40px courier";
				ctx.fillStyle="#FFFFFF";
				ctx.fillText("KAMU MATI",100,260);
				ctx.font="Bold 40px courier";
				ctx.fillText("SKOR MU: "+skor,100,360);
				ctx.fillStyle="#FFFFFF";
				var x = document.getElementById("target");
  				if (btnulang==true) {
    					x.style.display = "block";
  				}
				//ctx.drawImage(btnulang,135,460);
				//125,160
			}
			
			var skor =0, tambahnilai=true;
			function tambahskor (){
				skor++;
			}
			function kena(){
				for(var i=0;i<tiang.length;i++){
					var t = tiang[i];
					if((player.x+player.w>t.x && player.y<t.y+t.h && player.x<t.x+t.w)||(player.x+player.w>t.x && player.y+player.h>t.y+t.h+250 && player.x<t.x+t.w)){
						selesai (true);
						}else if(t.x+t.w<player.x){
							if(tambahnilai){
								point.play();
								tambahskor();
								tambahnilai=false;
								}
							}
				}
				if(player.y<=0){selesai (true);}
				if(player.y+player.h>ch){selesai (true);}
			}//batas function kena

			function rendertiang(){
				for(var i=0;i<tiang.length;i++){
					var t=tiang[i];
					ctx.drawImage(tg,t.x--,t.y);
					ctx.drawImage(tg,t.x--,t.y+t.h+250);
					if(t.x+t.w<0){
						tiang.splice(i,1);
						tambahnilai=true;
						}
					}
					hitung++;
					if(hitung==150){
						maketiang();
						hitung=0;
					}
				}
			function animation(){
				ctx.save();
				ctx.clearRect(0,0,cw,ch);
				latar.render();
				player.render();
				rendertiang();
				kena();
				ctx.fillStyle="#FFFFFF"
				ctx.font="Bold 50px Monospace";
				ctx.fillText(skor,160,60);
				ctx.restore();
			}//end animasi
			var interval = setInterval (animation,30);
			
			//untuk menaikkan karakter
			ctx.canvas.addEventListener("click",function(event){
				player.y-=75;
				ganti=true;
			});
			console.log("lokasi lagu: "+latar.x);
		}//batas fungsi game
		
	
	}
window.addEventListener("load", function (event){
start();
});

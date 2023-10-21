let main=document.getElementById('main');

let word=document.getElementById('word');
let character=document.getElementById('character');
main.addEventListener('input',function(){
    var text=this.value;
    let char=text.length;
    character.innerHTML=char;
    text=text.trim();
    let str=text.split(" ");
    let cleanList=str.filter(function(el){
        return el!="";
    })
    word.innerHTML=cleanList.length;
})
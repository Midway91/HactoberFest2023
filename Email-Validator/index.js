console.log("this is my commitment")
let result={
  "tag": "",
  "free": true,
  "role": false,
  "user": "abhayrai",
  "email": "abhayrai@gmail.com",
  "score": 0.64,
  "state": "deliverable",
  "domain": "gmail.com",
  "reason": "valid_mailbox",
  "mx_found": true,
  "catch_all": null,
  "disposable": false,
  "smtp_check": true,
  "did_you_mean": "",
  "format_valid": true
};

document.querySelector('.submitbtn').addEventListener("click",async(e)=>{
  e.preventDefault()
  console.log('Clicked');
  document.querySelector('.Validresult').innerHTML=` <img src="img/loading.gif" style="width: 90px;filter: invert(1);" alt="loading.gif">`
  let key="ema_live_hEEvYFTpVtBeLROHQYbEmVg29e56E4ap1HvMMyNO";
  let email=document.getElementById("username").value
  let url=`https://api.emailvalidation.io/v1/info?apikey=${key}&email=${email}`
  let res= await fetch(url);
  let result=await res.json();
  let str='';
for(key of Object.keys(result)){
  // console.log(item)
  if(result[key]!=="" && result[key]!==" "){
    str=str+`<div>${key}:${result[key]}</div>`
    //saari keys div ki form me store kiya hai str me. 
  }

}
console.log(str)
document.querySelector('.Validresult').innerHTML=str

})



function generate(){
    let arr = ''
       document.querySelector('input[type="text"]').value= "passsword"

      if(document.getElementById('upperCB').checked){
           arr+= 'QWERTYUIOPASDFGHJKLZXCVBNNM'
      
        }

    
    if(document.getElementById('lowerCB').checked){
            arr+= 'qwertyuiopasdfghjklzxcvbnm'
       }

    
    if(document.getElementById('numberCB').checked){
        arr+= '0123456789'
   }
   
   if(document.getElementById('specialCB').checked){
    arr+= '!@#$%^&*()'
   }

   const length = document.querySelector('input[type="range"]').value;
   console.log(length)
   if(length<1 || arr.length===0){
      return
   }
   let password = ''
   for(let i=0;i<length;i++){
        
       const position = Math.floor(Math.random()*arr.length)
       password +=arr[position]
   }
   console.log(arr)
   console.log(password)


   document.querySelector('input[type="text"]').value = password;

   [...document.querySelectorAll('input[type="checkbox"],button.generate')].forEach(element => {
              element.addEventListener('click',generate);
   })

   document.querySelector('input[type="range"]').addEventListener('input',()=>{
    document.querySelector('div.range-main span').innerHTML = document.querySelector('input[type="range"]').value
    generate();
   })

   document.querySelector('div.input-main button').addEventListener('click',()=>{
       const pass = document.querySelector('input[type="text"]').value
       navigator.clipboard.writeText(pass).then(()=>{
           document.querySelector('div.input-main button').innerHTML = "Copied!"
           setTimeout(()=>{
            document.querySelector('div.input-main button').innerHTML = "Copy"
           },1000)
       })
   })

}

  
  
  
   


generate()

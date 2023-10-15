let result = document.getElementById("result");
const themeChanger = document.querySelector('.ThemeChanger');
const darkThemeButton = document.querySelector('.ChangeDarkTheme');
const lightThemeButton = document.querySelector('.ChangeLightTheme');
const buttons = document.querySelectorAll('.buttons button');
const CalcBody = document.querySelector('.calculator');

function appendToResult(key) {
    var val=result.value;
    if(isOperatorKey(key))
    {
        var len=val.length; 
        if(len==0)   
           val="0"+key;
        else if(isOperatorKey(val.charAt(len-1))) //check for last appended key ,if last appended key was an opearator ,overwrite that with current operator  
            val=val.slice(0,-1)+key;
        else 
            val=val+key;
    }
    else 
       val=val+key;
    result.value=val;
}

function isOperatorKey(key)
{
    if(key=='+'||key=='-'||key=='*'||key=='/')
      return true;
    else 
      return false;
}
function backSpace()
{
    result.value=result.value.slice(0,-1)
}
function clearResult() {
    result.value = "";
}

function calculateResult() {
    try {
        result.value = eval(result.value);
    } catch (error) {
        result.value = "Error";
    }
}

darkThemeButton.addEventListener('click', () => {
    document.body.style.backgroundColor = '#333';
    document.body.style.color = '#fff';
    themeChanger.style.backgroundColor = '#444';
    CalcBody.style.backgroundColor = '8b8181';
    buttons.forEach(button => {
        button.style.backgroundColor = '#0f2337';
    })
})

lightThemeButton.addEventListener('click', () => {
    document.body.style.backgroundColor = '#fff';
    document.body.style.color = '#000';
    themeChanger.style.backgroundColor = '#eee';
    CalcBody.style.backgroundColor = 'fff';
    buttons.forEach(button => {
        button.style.backgroundColor = '#007bff';
    })
    
})
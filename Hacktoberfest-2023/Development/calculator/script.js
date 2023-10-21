let result = document.getElementById("result");
const themeChanger = document.querySelector('.ThemeChanger');
const darkThemeButton = document.querySelector('.ChangeDarkTheme');
const lightThemeButton = document.querySelector('.ChangeLightTheme');
const buttons = document.querySelectorAll('.buttons button');
const CalcBody = document.querySelector('.calculator');

function appendToResult(value) {
    result.value += value;
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
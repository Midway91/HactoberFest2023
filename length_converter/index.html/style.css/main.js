var input = document.getElementById('input'),
    result = document.getElementById('result'),
    inputType = document.getElementById('inputType'),
    resultType = document.getElementById('resultType'),
    inputTypeValue , resultTypeValue;

input.addEventListener('keyup' , myResult)
inputType.addEventListener('change' , myResult)
resultType.addEventListener('change' , myResult)

inputTypeValue = inputType.value
resultTypeValue = resultType.value

function myResult(){
    inputTypeValue = inputType.value
    resultTypeValue = resultType.value

    if(inputTypeValue === 'meter' && resultTypeValue === 'kilometer'){
        result.value = Number(input.value) * 0.001
    } else if(inputTypeValue === 'meter' && resultTypeValue === 'centimeter'){
        result.value = Number(input.value) * 100
    } else if(inputTypeValue === 'meter' && resultTypeValue === 'meter'){
        result.value = input.value
    }
    else if(inputTypeValue==='meter' && resultTypeValue==='hectometer'){
       result.value=Number(input.value)*0.01
    }
    else if(inputTypeValue==='meter' && resultTypeValue==='decameter'){
        result.value=Number(input.value)*0.1
     }
     else if(inputTypeValue==='meter' && resultTypeValue==='decimeter'){
        result.value=Number(input.value)*10
     }
     else if(inputTypeValue==='meter' && resultTypeValue==='millimeter'){
        result.value=Number(input.value)*1000
     }


    if(inputTypeValue === 'kilometer' && resultTypeValue === 'meter'){
        result.value = Number(input.value) * 1000
    } else if(inputTypeValue === 'kilometer' && resultTypeValue === 'centimeter'){
        result.value = Number(input.value) * 100000
    } else if(inputTypeValue === 'kilometer' && resultTypeValue === 'kilometer'){
        result.value = input.value
    }
    else if(inputTypeValue === 'kilometer' && resultTypeValue === 'hectometer'){
        result.value = Number(input.value)*10
    }
    else if(inputTypeValue === 'kilometer' && resultTypeValue === 'decameter'){
        result.value = Number(input.value)*100
    }
    else if(inputTypeValue === 'kilometer' && resultTypeValue === 'decimeter'){
        result.value = Number*(input.value)*10000
    }
    else if(inputTypeValue === 'kilometer' && resultTypeValue === 'millimeter'){
        result.value = Number(input.value)*1000000
    }


    if(inputTypeValue === 'centimeter' && resultTypeValue === 'kilometer'){
        result.value = Number(input.value) * 0.00001
    } else if(inputTypeValue === 'centimeter' && resultTypeValue === 'meter'){
        result.value = Number(input.value) * 0.01
    } else if(inputTypeValue === 'centimeter' && resultTypeValue === 'centimeter'){
        result.value = input.value
    }
    else if(inputTypeValue === 'centimeter' && resultTypeValue === 'hectometer'){
        result.value = Number(input.value)*0.0001
    }else if(inputTypeValue === 'centimeter' && resultTypeValue === 'decameter'){
        result.value = Number(input.value)*0.001
    }else if(inputTypeValue === 'centimeter' && resultTypeValue === 'decimeter'){
        result.value = Number(input.value)*0.1
    }else if(inputTypeValue === 'centimeter' && resultTypeValue === 'millimeter'){
        result.value = Number(input.value)*10
    }


    if(inputTypeValue === 'hectometer' && resultTypeValue === 'kilometer'){
        result.value = Number(input.value) * 0.1
    } else if(inputTypeValue === 'hectometer' && resultTypeValue === 'meter'){
        result.value = Number(input.value) * 100
    } else if(inputTypeValue === 'hectometer' && resultTypeValue === 'centimeter'){
        result.value = Number(input.value)*10000
    }
    else if(inputTypeValue === 'hectometer' && resultTypeValue === 'hectometer'){
        result.value = input.value
    }else if(inputTypeValue === 'hectometer' && resultTypeValue === 'decimeter'){
        result.value = Number(input.value)*1000
    }else if(inputTypeValue === 'hectometer' && resultTypeValue === 'decameter'){
        result.value = Number(input.value)*10
    }else if(inputTypeValue === 'hectometer' && resultTypeValue === 'millimeter'){
        result.value = Number(input.value)*100000
    }

    if(inputTypeValue === 'decimeter' && resultTypeValue === 'kilometer'){
        result.value = Number(input.value) * 0.0001
    } else if(inputTypeValue === 'decimeter' && resultTypeValue === 'meter'){
        result.value = Number(input.value) * 0.1
    } else if(inputTypeValue === 'decimeter' && resultTypeValue === 'centimeter'){
        result.value = Number(input.value)*10
    }
    else if(inputTypeValue === 'decimeter' && resultTypeValue === 'hectometer'){
        result.value = Number(input.value)*0.001
    }else if(inputTypeValue === 'decimeter' && resultTypeValue === 'decimeter'){
        result.value = input.value
    }else if(inputTypeValue === 'decimeter' && resultTypeValue === 'decameter'){
        result.value = Number(input.value)*0.01
    }else if(inputTypeValue === 'decimeter' && resultTypeValue === 'millimeter'){
        result.value = Number(input.value)*100
    }

    if(inputTypeValue === 'decameter' && resultTypeValue === 'kilometer'){
        result.value = Number(input.value) * 0.01
    } else if(inputTypeValue === 'decameter' && resultTypeValue === 'meter'){
        result.value = Number(input.value) * 10
    } else if(inputTypeValue === 'decameter' && resultTypeValue === 'centimeter'){
        result.value = Number(input.value)*1000
    }
    else if(inputTypeValue === 'decameter' && resultTypeValue === 'hectometer'){
        result.value = Number(input.value)*0.1
    }else if(inputTypeValue === 'decameter' && resultTypeValue === 'decimeter'){
        result.value = Number(input.value)*100
    }else if(inputTypeValue === 'decameter' && resultTypeValue === 'decameter'){
        result.value = input.value
    }else if(inputTypeValue === 'decameter' && resultTypeValue === 'millimeter'){
        result.value = Number(input.value)*10000
    }

    if(inputTypeValue === 'millimeter' && resultTypeValue === 'kilometer'){
        result.value = Number(input.value) * 0.000001
    } else if(inputTypeValue === 'millimeter' && resultTypeValue === 'meter'){
        result.value = Number(input.value) * 0.001
    } else if(inputTypeValue === 'millimeter' && resultTypeValue === 'centimeter'){
        result.value = Number(input.value)*0.1
    }
    else if(inputTypeValue === 'millimeter' && resultTypeValue === 'hectometer'){
        result.value = Number(input.value)*0.00001
    }else if(inputTypeValue === 'millimeter' && resultTypeValue === 'decimeter'){
        result.value = Number(input.value)*0.01
    }else if(inputTypeValue === 'millimeter' && resultTypeValue === 'decameter'){
        result.value = Number(input.value)*0.0001
    }else if(inputTypeValue === 'millimeter' && resultTypeValue === 'millimeter'){
        result.value = input.value
    }

}

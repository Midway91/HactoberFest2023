let inputEl = document.querySelector("#txt_text");
let btnAdd = document.querySelector("#add");
let taskDiv = document.querySelector(".bottom");
let taskArray = localStorage.getItem("tasks") ? JSON.parse(localStorage.getItem("tasks")) : [];



btnAdd.addEventListener("click", (e) => {
    AddValue();
});

inputEl.addEventListener("keydown", (e) => {
    if (e.keyCode === 13) {
        AddValue();
    }
});


function AddValue() {
    let inputElVal = inputEl.value;
    if (inputEl.value !== "") {
        addTaskToArray(inputEl.value);
        inputEl.value = " ";
    }
}

//funtion Add data to Task Array
function addTaskToArray(val) {
    const items = {
        id: taskArray.length,
        taskName: val,
        completed: false
    };
    taskArray.push(items);
    addTaskToLocalStorage(taskArray);
    showTasks(taskArray);
}


//function add task Array to local storage
function addTaskToLocalStorage(taskArray) {
    localStorage.setItem("tasks", JSON.stringify(taskArray));
}

//function show tasks in the page
function showTasks(taskArray) {
    //empty Task Div 
    taskDiv.innerHTML = "";
    //Looping on task array 
    taskArray.forEach((task) => {
        //create done button
        let checkDiv = document.createElement("i");
        checkDiv.className = "fas fa-check finish";
        //create parent div
        let div = document.createElement("div");
        div.className = "task";
        if (taskArray.completed) {
            div.className = "task done";
        }
        div.setAttribute("data-id", task.id);
        //Create delete button
        let deleteDiv = document.createElement("i");
        deleteDiv.className = "fas fa-trash delete";
        let p = document.createElement("p");
        let pText = document.createTextNode(task.taskName);
        p.appendChild(pText);
        //Append Element to main div
        div.appendChild(checkDiv);
        div.appendChild(p);
        div.appendChild(deleteDiv);
        //Add div to taskDiv
        taskDiv.appendChild(div);
    });
}

showTasks(taskArray);

//Delete Task
taskDiv.addEventListener("click", (e) => {
    if (e.target.classList.contains("delete")) {
        e.target.parentElement.remove();
        deleteTaskFromLocalStorage(e.target.parentElement.getAttribute("data-id"));
    } else {
        e.target.parentElement.classList.toggle("done");
        updateTask(e.target.parentElement.getAttribute("data-id"));
    }
})

function deleteTaskFromLocalStorage(taskId) {
    taskArray = taskArray.filter((item) => item.id != taskId);
    addTaskToLocalStorage(taskArray);
}

function updateTask(taskId) {
    //loop on taskArray
    for (let i = 0; i < taskArray.length; i++) {
        //check task id = taskId
        if (taskArray[i].id == taskId) {
            //Change task completed to true if it's false and false if it's true
            taskArray[i].completed == false ? (taskArray[i].completed = true) : (taskArray[i].completed = false)
        }
    }
    addTaskToLocalStorage(taskArray);
}
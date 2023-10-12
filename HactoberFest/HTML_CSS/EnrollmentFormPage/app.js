

var Name = document.getElementById('Name')
var Email = document.getElementById('Email')
var website = document.getElementById('website')
var btn = document.getElementById('btn');
var cards = document.querySelector('.cards');
var Male = document.getElementById('Male')
var Female = document.getElementById('Female')
var html = document.getElementById('html')
var css = document.getElementById('css')
var javascript = document.getElementById('javascript')
var form = document.querySelector('form');
var selectImage;

var image = function (event) {
 selectImage = URL.createObjectURL(event.target.files[0]);
};


btn.addEventListener('click', function () {


  let checkboxes = document.querySelectorAll('input[type="checkbox"]:checked');
  let values = []
  checkboxes.forEach((checkbox) => {
    values.push(checkbox.value);
  });


  if (!Name.value || !Email.value || !website.value ) {
    alert('ERROR: Please enter all fields! 😔 ')
  }
  else {
    cards.innerHTML += `
  <div class="card">
  <div class="image">
      <img src='${selectImage}' alt="Image">
    </div>
      <div class="card-body">
        <h4 class="title">${Name.value}</h4>
        <p class="text">${Male.checked ? Male.value : Female.checked ? Female.value : 'Others'}</p>
        <p class="text">${Email.value}</p>
        <p class="text">${website.value}</p>
        <p class="text">${values}</p>
      </div>
  </div>`

    alert(' Wohoo!!  Student Enrolled Successfully!!!! 😁 😄')
    form.reset()
  }

});
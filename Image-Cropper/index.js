const image_input = document.querySelector("#image-input");

image_input.addEventListener("change", function() {
  const reader = new FileReader();
  reader.addEventListener("load", () => {
    const uploaded_image = reader.result;
    document.getElementById("image").src = uploaded_image;
    const image = document.getElementById("image");
    const cropper = new Cropper(image,{
        aspectRatio : 0,
        viewMode : 0,
    });
    document.getElementById("cropButton").addEventListener('click',function(){
        var croppedImage = cropper.getCroppedCanvas().toDataURL("image/png");
        // document.getElementById("croppedImage").src=croppedImage;
        var termImg = document.createElement("img");
        // termImg.setAttribute('height',"100%");
        // termImg.setAttribute('width',"100%");
        termImg.setAttribute('src',croppedImage);
        var termDiv = document.createElement("div");
        termDiv.setAttribute('class','item');
        termDiv.append(termImg);
        var termWrapper = document.getElementById("wrapper");
        termWrapper.append(termDiv);
    });
  });
  reader.readAsDataURL(this.files[0]);
});

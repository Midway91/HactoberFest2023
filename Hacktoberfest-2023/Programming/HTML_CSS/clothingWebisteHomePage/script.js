'use strict';

///////////////////////////////////////
// Modal window

const modal = document.querySelector('.modal');
const overlay = document.querySelector('.overlay');
const btnCloseModal = document.querySelector('.btn--close-modal');
const btnsOpenModal = document.querySelectorAll('.btn--show-modal');

const openModal = function (e) {
  e.preventDefault();   
  modal.classList.remove('hidden');
  overlay.classList.remove('hidden');
};

const closeModal = function () {
  modal.classList.add('hidden');
  overlay.classList.add('hidden');
};

for (let i = 0; i < btnsOpenModal.length; i++)
  btnsOpenModal[i].addEventListener('click', openModal);

btnCloseModal.addEventListener('click', closeModal);
overlay.addEventListener('click', closeModal);

document.addEventListener('keydown', function (e) {
  if (e.key === 'Escape' && !modal.classList.contains('hidden')) {
    closeModal();
  }
});
 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

const allSections = document.querySelectorAll('.section') ; 
const allButtons = document.getElementsByTagName('button') ; 

//creating and inserting elements 
// -----------------------------------------------------------------
//.insertAdjacentHTML 
// const message = document.createElement('div') ;
// message.classList.add('cokkie-message') ; 
// message.textContent = 'We use cokkied to improve functionalites and analytics' ; 
// header.prepend(message) ;  
// header.append(message.cloneNode(true ))  ; // clones a element used previously 
// same message in both the places

//------------------------------------------------------------------

// delete elements -- 
// element.remove( ) // remove( ) method to delete a element 

//------------------------------------------------------------------

// Styles :- 

// to set a style on an element
// element.style.property = "value"  
// eg - 
// body.style.background-color = "blue"  
// getComputedStyle( ) function -- to get style of the element from css 
// getComputedStyle(element).property) ; 

// CSS CUSTOM PROPERTIES 

// Document.documentElement.style.setProperty('')

// -----------------------------------------------------

const ButtonScrollTo = document.querySelector('.btn--scroll-to') ; 

// ButtonScrollTo.addEventListener('click' , function ( e ) { 
//    const s1cords = section1.getBoundingClientRect(); 
//     basically to get Coordinates of the required section 
//    window.scrollTo( { 
//     left : s1cords.left ,  // window scroolTo( ) function to specify scroll properties 
//     top : s1cords.top + window.pageYOffset ,  // old school way 
//     behavior : 'smooth' , 
//    }
     
//    )
//  }) 
 
// -----------------------------------------------------// 
ButtonScrollTo.addEventListener('click' , function(e){ 
  e.preventDefault( ); 
  section1.scrollIntoView(  ) ; 
})
//-------------------------------------------------------// 
// mouse enter event 
const h1 = document.querySelector('h1') ; 

// h1.addEventListener('mouseenter' , function( e) { 
// //  mouse enter is basically like hover in css 
//    alert('Happy Learning Javascript ') ; 
  
// })

// directly attachiing events 

// h1.onmouseenter = function ( e ) { 
//    alert( "hello bhaisaab")
// }

// Removing the event Handler  
// const SayHello = function (e) { 
//    alert("hello Bhai") ; 
//    h1.removeEventListener('mouseenter' , SayHello) ; 
// }
// h1.addEventListener('mouseenter' , SayHello) ; 

// rgb( 255 , 255 , 255) 
// EVENT BUBBLING --------------------------------
// const randomInt = ( min , max ) => Math.trunc( Math.random( ) * ( max - min + 1 ) + min ) ;  
// const randomColor =  function()  { 
//     return  `rgb(${randomInt(0 , 255 )} ,${randomInt(0 , 255 )} , ${randomInt(0 , 255 )})` ;
// }
// console.log(randomColor( )) ;  
// document.querySelector('.nav__link').addEventListener( 'click' ,function ( ){  
//    this.style.backgroundColor = randomColor() ;
// })
// document.querySelector('.nav__links').addEventListener( 'click' ,function ( ){  
//   this.style.backgroundColor = randomColor() ;
// })
// document.querySelector('nav').addEventListener( 'click' ,function ( ){  
//   this.style.backgroundColor = randomColor() ;
// })
// -----------------------------------------------------------------------------------------------//
// 
const tabsContainer  = document.querySelector('.operations__tab-container') ; 
const tabs = document.querySelectorAll('.operations__tab')
const tabsContent = document.querySelectorAll('.operations__content') ; 


// tabs.forEach(t=>t.addEventListener('click' , () => { 
     // bad method
// }))
tabsContainer.addEventListener('click' , function (e) { 
   const clicked = e.target.closest('.operations__tab'); 
   if(!clicked) return ;   
   tabsContent.forEach(x=>x.classList.remove('operations__content--active')) ;
   tabs.forEach(t=>t.classList.remove('operations__tab--active')) ; // putting buttons down 
   clicked.classList.add('operations__tab--active') ; 
   // Active Content Area 
  document.querySelector(`.operations__content--${clicked.dataset.tab}`).classList.add('operations__content--active') ; 
  
})

// Menu fade Animation 
const nav = document.querySelector('.nav')  ; 

const handleHover =  function (e, opacity ) {
  if(e.target.classList.contains('nav__link')){ 
    const link= e.target ; 
    const siblings = link.closest('.nav').querySelectorAll('.nav__link') ; 
    const logo = link.closest('.nav').querySelector('img')
    siblings.forEach( el => { 
       if ( el !== link ) {
         el.style.opacity = opacity ; 
         logo.style.opacity = opacity ; 
      }
    })
    }
}



nav.addEventListener('mouseover'  , function (e) { 
     handleHover( e , 0.5 ) ; 
})  ; 
nav.addEventListener('mouseout'  , function ( e ) { 
    handleHover( e , 1 ) ; 
})  ; 


// // Making the Navigation Sticky --> --> 
const section1 = document.querySelector('#section--1') ;
const s1cords = section1.getBoundingClientRect(); 
// window.addEventListener('scroll' ,function() { 
//    if( window.scrollY > s1cords.top ){ 
//      nav.classList.add('sticky')
//    }
//    nav.classList.add('sticky') ; 
// }
// )
// ------------------------------------------------//

// Intersection observer Api 
// const obsCallBack = function (entries , observer ) { 
//      entries.forEach( entry => { 
      
//      })
// }; 
// const obsoptions = {
//   root : null , 
//   threshold : [0 , 0.2 ],
// } ; 
// const observer = new IntersectionObserver(obsCallBack  , obsoptions) ; 
// observer.observe(section1) ; 
// more Optimized Method 
const header = document.querySelector('.header') ; 
const navHeight = nav.getBoundingClientRect().height ;
const StickyNav = function (entries) { 
    const [entry] = entries ; 
    // console.log(entry) ;  // when Intersection Ratio is 0 
    if(!entry.isIntersecting)
    nav.classList.add('sticky')  ;
    else{ 
      nav.classList.remove('sticky')  ;
    } 
}
const headerObserver = new IntersectionObserver(StickyNav , { 
    root:null ,
    threshold : 0, // when header is 0% visible we add the nav
    rootMargin : '-100px' ,  
}) ; 
headerObserver.observe(header);

// Reveal Sections 
const AllSections = document.querySelectorAll('.section') ; 
const revealSection = function ( entries , Observer ) { 
   const [entry] = entries ; 
   if(!entry.isIntersecting) return ; 
   entry.target.classList.remove('section--hidden') ; 
   Observer.unobserve(entry.target) ; 
}

const sectionObserver = new IntersectionObserver( revealSection , { 
   root : null , 
   threshold :0.15 , 
   
}) ; 
AllSections.forEach(function ( section ){ 
   sectionObserver.observe(section);  
   section.classList.add('section--hidden') ; 
})

//Lazy Loading Images  - - - - - - - - - - - - - - - - 

const imgTargets = document.querySelectorAll('img[data-src]') ; 

const loadImg = function ( entries , observer ) { 
     const [entry] = entries ; 
     if(!entry.isIntersecting ) return ; 
     // replace the src with data-src - - - - - 
     entry.target.src = entry.target.dataset.src ; 
     entry.target.addEventListener('load' , function ( ) { 
       entry.target.classList.remove('lazy-img') ; 
     })
     observer.unobserve(entry.target) ; 
} ; 
const ImgObserver = new IntersectionObserver(loadImg, { 
   root:null , 
   threshold:0 , 
   rootMargin:'200px' 
})
imgTargets.forEach(img => ImgObserver.observe( img )) ; 

const slides = document.querySelectorAll('.slide') ; 
const slider = document.querySelector('.slider') ; 
// slider.style.transform = 'scale(0.5)' ; 



const btnLeft  = document.querySelector('.slider__btn--left') ; 


const btnRight  = document.querySelector('.slider__btn--right') ; 

let curSlide = 0 ;
const maxSlide = slides.length ; 

const dotContainer = document.querySelector('.dots') ; 
const createDots  = function ( ) { 
    slides.forEach( ( _ , i ) => { 
       dotContainer.insertAdjacentHTML('beforeend' , `<button class = "dots__dot" data-slide ="${i}"> </button>`) ; 

    } ) 
}
const goToSlide = function (slide) { 
  curSlide = slide  ; 
  
  slides.forEach(( s , i ) => s.style.transform = `translateX(${(i - curSlide) * 100 }%)`) ; 
  activateDot(slide) ; 
}

createDots( ) ; 


const activateDot = function ( slide ) { 
    
    document.querySelectorAll('.dots__dot').forEach( dot => dot.classList.remove('dots__dot--active')) ; 
    document.querySelector(`.dots__dot[data-slide ='${slide}']`).classList.add('dots__dot--active') ; 
}
dotContainer.addEventListener('click' , function ( e ) {
   if ( e.target.classList.contains('dots__dot')) { 
    const slide = e.target.dataset.slide ; 
    goToSlide( slide ) ; 
    activateDot( slide ) ; 
   }
})




btnRight.addEventListener('click' , function () { 
  
  if( curSlide === maxSlide - 1) curSlide = 0 ; 
  else  curSlide++ ; 
  
  slides.forEach(( s , i ) => s.style.transform = `translateX(${(i - curSlide) * 100 }%)`) ; 
  activateDot( curSlide)
  
})
btnLeft.addEventListener('click' , function ( ) { 
  if( curSlide === 0 ) curSlide = maxSlide -1  ; 
  else  curSlide-- ; 
  
  slides.forEach(( s , i ) => s.style.transform = `translateX(${(i - curSlide) * 100 }%)`) ; 
  activateDot( curSlide) ; 
  
})

goToSlide(0) ; 



































































































































































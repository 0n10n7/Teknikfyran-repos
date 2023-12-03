
function addToCart(parentName) {
    let cartItem = document.createElement('li');
    cartItem.innerHTML=parentName;
    let cart = document.querySelector(".cart");
    cart.append(cartItem);
}

function removeFromCart(){
    console.log("Doesn't do anything yet :)");
}
function addShoppableItem(Name,Price,){
    let shoppableItem = document.createElement('div');
    let name = document.createElement('p');
    let price = document.createElement('p');
    let buttonAdd = document.createElement('button');
    
    shoppableItem.classList.add("shoppableItem");
    name.innerHTML=Name;
    price.innerHTML=`pris: ${Price}`;
    buttonAdd.addEventListener("click", () => {
        addToCart(name.innerHTML)
    });
    buttonAdd.innerHTML="add to cart";
    
    let div = document.querySelector(".shoppingWindow");
    div.append(shoppableItem);
    shoppableItem.append(name);
    shoppableItem.append(price);
    shoppableItem.append(buttonAdd);
}
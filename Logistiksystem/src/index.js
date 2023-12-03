import { PollingWatchKind, textChangeRangeIsUnchanged } from "typescript";

const OrderStates = Object.freeze({
	Summer: Symbol("summer"),
	Autumn: Symbol("autumn"),
	Winter: Symbol("winter"),
	Spring: Symbol("spring")
});
const JobTitle = Object.freeze({
	Picker: Symbol("picker"),
	Driver: Symbol("driver"),
	Mix: Symbol("mix")
});
class Order {
    //productType should be Product
    //wareHouseIndex should be an integer
    //picker should be a Worker
    constructor(productType,warehouseIndex,picker) {
      this.productType = productType;
      this.warehouseIndex = warehouseIndex;
      this.picker = picker;
      this.status = 0;
    }
    FindPicker() {
        //calculate distance from a picker to shelf number using manhattan distance.
        //One of the distances needs to be multiplied with 5, either x or y depending on shelf oriantation
        //Distance is calculated from youngest active order asigned to a picker

    }
}
class Worker {
    constructor(job){
        this.jobTitle = job;
        this.orderList = []; 
    }
}
class Product {
    constructor(name,weight,price){
        this.name = name;
        this.weight = weight;
        this.price = price;
    }
}
let warehouses = [];
let products = [];
function CreateWarehouse(name) {
    let warehouse = {
        locationName: name,
        productsInStock: [],

    };
    warehouses.push(warehouse);
}
function GenerateData(){
    products.push(new Product("Brass: Birmingham", 1000, "800 Kr"));
    products.push(new Product("Brass: Lancashire", 1000, "800 Kr"));
    products.push(new Product("Brass: Stoke-on-Trent", 1000, "800 Kr"));
    products.push(new Product("Brass: Sevenoaks", 1000, "800 Kr"));
    products.push(new Product("Brass: Tonnebridge", 1000, "800 Kr"));
    products.push(new Product("Brass: Exiter", 1000, "800 Kr"));
    products.push(new Product("Brass: London", 1000, "700 Kr"));
    CreateWarehouse("Bismark");
}

GenerateData();
//Javapoint has good theory and illustation on function ,object and class
//Function in javascript
//1. Normal function
function car()
{
    var k=15;
    return k;
}
document.write(car());
document.write("<br>");

//2. What if we dont put () after function name
var car= function()
{
    var k=15;
    return k;
}
document.write(car);
document.write("<br>");

//3. anonymous function 
var car= function()
{
    var k="Anonymous";
    return k;
}
document.write(car());
document.write("<br>");

//4.self executing anonymous function
(function()
{
    document.write("Self Executing");
})()
document.write("<br>");

//5.Arrow function
var car = ()=> {return "Arrow"} ;
document.write(car());
document.write("<br>");


//Creating Objects 
//1.by object literal
emp={id:102,name:"Shyam Kumar",salary:40000}  
document.write(emp.id);  
document.write("<br>");

//2.Creating instance of object
var school= new Object();
school.parking=200;
school.name="AKVS";
document.write(school.name);
document.write("<br>");

//3.object constructor
function Myself()
{
    this.name="Amit";
    this.game="pubg";
    var age=5;   //private member
}
me=new Myself();
document.write(me.name+" "+me.age);
document.write("<br>");



//Classes in JAVASCRIPT
//1.class declaration
//Declaring class  
class Employee  
  {  
//Initializing an object  
    constructor(id,name)  
    {  
      this.id=id;  
      this.name=name;  
    }  
//Declaring method  
    detail()  
    {  
  document.writeln(this.id+" "+this.name+"<br>")  
    }  
  }  
//passing object to a variable   
var e1=new Employee(101,"Martin Roy");  
var e2=new Employee(102,"Duke William");  
e1.detail(); //calling method  
e2.detail();  

//2.unnamed Class expression
var emp = class {  
    constructor(id, na) {  
      this.id = id;  
      this.name= na;  
    }  
  };  
var e3=new emp(2,"red");
document.write(e3.name);  


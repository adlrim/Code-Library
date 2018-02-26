let myPlaces=[1,2,3,4];
let friendPlaces=[5,6,7,8];
for(let myPlacesIndex=0;myPlacesIndex<myPlaces.length;myPlacesIndex++)
  {
    console.log(myPlaces[myPlacesIndex]);
    for(let friendPlacesIndex=0;friendPlacesIndex<friendPlaces.length;friendPlacesIndex++)
      {

        console.log(`we have reached to ${friendPlaces[friendPlacesIndex]}`);
      }
  }

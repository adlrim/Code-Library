console.log(process.argv);
let sum=0;
for(let Index=2;Index<process.argv.length;Index++)
  {
    sum=sum+Number(process.argv[Index]);
  }
  console.log(1+2);
console.log(`my sum is ${sum}`);

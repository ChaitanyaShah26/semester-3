// Create & Use Database:
use Experiment11;

// Create Collection:
db.createCollection('Emp');

// Insert Data in collection:
db.Emp.insertMany( [
	{ "eid": 1, "ename": "Alice Johnson", "eage": 30, "esal": 60000 }, 
	{ "eid": 2, "ename": "Bob Smith", "eage": 25, "esal": 50000 }, 
	{ "eid": 3, "ename": "Charlie Brown", "eage": 35, "esal": 75000 }, 
	{ "eid": 4, "ename": "Diana Prince", "eage": 28, "esal": 55000 } 
	] )

// Display data from collection:
db.Emp.find();

// Find specific data:
db.Emp.find({"ename":"Charlie Brown"});

// Update data: 
db.Emp.update({"eid":1},{$set:{"esal":75000}});
db.Emp.find({"eid":1});

// Delete single data: 
db.Emp.deleteOne({"eid":3});
db.Emp.find().pretty();

// Aggregation:
db.Emp.aggregate([{$group:{_id:"$eage", same_age:{$sum:1}}}]);

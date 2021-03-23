-- Write your MySQL query statement below

SELECT Name AS 'Customers' 
FROM Customers 
WHERE Customers.Id 
NOT IN (SELECT CustomerId FROM Orders);
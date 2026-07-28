# Write your MySQL query statement below
SELECT x.name, y.bonus FROM Employee AS x LEFT JOIN Bonus AS y 
ON x.empID=y.empID WHERE bonus < 1000 OR bonus IS NULL;
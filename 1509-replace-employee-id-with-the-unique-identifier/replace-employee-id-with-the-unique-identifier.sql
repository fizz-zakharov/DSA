# Write your MySQL query statement below
SELECT y.unique_id AS unique_id, x.name AS name
FROM Employees AS x LEFT JOIN EmployeeUNI AS y
ON x.id=y.id;
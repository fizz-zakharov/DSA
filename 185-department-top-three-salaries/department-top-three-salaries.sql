# Write your MySQL query statement below
SELECT y.name AS Department,x.name AS Employee,
x.salary AS Salary
FROM Employee x
JOIN Department y
ON x.departmentId=y.id
WHERE 3>(
    SELECT COUNT(DISTINCT e2.salary)
    FROM Employee e2
    WHERE e2.departmentId=x.departmentId
    AND e2.salary>x.salary
);
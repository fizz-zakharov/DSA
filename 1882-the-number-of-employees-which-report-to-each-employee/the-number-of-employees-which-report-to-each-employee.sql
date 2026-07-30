# Write your MySQL query statement below
SELECT x.employee_id,x.name,
COUNT(y.reports_to) AS reports_count, ROUND(AVG(y.age)) AS average_age
FROM Employees AS x
JOIN Employees AS y
ON x.employee_id=y.reports_to
GROUP BY x.employee_id
ORDER BY x.employee_id;
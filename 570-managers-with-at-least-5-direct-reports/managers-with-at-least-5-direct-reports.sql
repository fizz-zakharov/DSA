# Write your MySQL query statement below
SELECT x.name FROM Employee AS x JOIN Employee as y ON x.id=y.managerId
GROUP BY x.id,x.name HAVING COUNT(y.managerId)>=5;
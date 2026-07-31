# Write your MySQL query statement below
DELETE x
FROM Person x
JOIN Person y
ON x.id>y.id AND x.email=y.email;
# Write your MySQL query statement below
SELECT x.id FROM Weather AS x JOIN Weather AS y 
ON DATEDIFF(x.recordDate,y.recordDate)=1 WHERE 
x.temperature > y.temperature;
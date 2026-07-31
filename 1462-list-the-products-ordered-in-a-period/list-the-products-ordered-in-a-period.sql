# Write your MySQL query statement below
SELECT x.product_name AS product_name ,SUM(y.unit) AS unit
FROM Products x
JOIN Orders y
ON x.product_id=y.product_id AND MONTH(y.order_date)=02 AND YEAR(y.order_date)=2020
GROUP BY y.product_id HAVING SUM(y.unit)>=100;
# Write your MySQL query statement below
SELECT x.product_id, IFNULL(ROUND(SUM(x.price*y.units)/SUM(y.units),2),0) AS average_price
FROM Prices AS x
LEFT JOIN UnitsSold AS y
ON x.product_id = y.product_id
AND y.purchase_date>=x.start_date
AND y.purchase_date<=x.end_date
GROUP BY x.product_id;
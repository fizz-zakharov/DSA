# Write your MySQL query statement below
SELECT y.product_name AS product_name, x.year AS year, x.price AS price
FROM Sales AS x LEFT JOIN Product AS y
ON x.product_id=y.product_id;
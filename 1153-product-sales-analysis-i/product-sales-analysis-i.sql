# Write your MySQL query statement below
SELECT x.product_name, y.year ,y.price FROM Product AS x
INNER JOIN Sales AS y ON x.product_id=y.product_id;
# Write your MySQL query statement below
SELECT x.customer_id, COUNT(x.customer_id) AS count_no_trans
FROM Visits AS x LEFT JOIN Transactions AS y ON x.visit_id=y.visit_id
WHERE y.transaction_id IS NULL GROUP BY x.customer_id;
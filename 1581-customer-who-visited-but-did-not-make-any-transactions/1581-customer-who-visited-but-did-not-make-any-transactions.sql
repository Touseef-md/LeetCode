# Write your MySQL query statement below
SELECT Visits.customer_id,COUNT(Visits.visit_id) as count_no_trans FROM Visits LEFT JOIN Transactions ON Visits.visit_id=Transactions.visit_id WHERE Transactions.transaction_id IS NULL GROUP BY Visits.customer_id

# SELECT v.customer_id, COUNT(v.visit_id) AS count_no_trans 
# from Visits v 
# LEFT JOIN Transactions t 
# ON v.visit_id = t.visit_id  
# WHERE t.transaction_id IS NULL 
# GROUP BY v.customer_id; 
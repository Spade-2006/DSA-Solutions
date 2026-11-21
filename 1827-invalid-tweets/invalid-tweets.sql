-- Write your PostgreSQL query statement below
Select tweet_id from Tweets where length(content) > 15;

select  R.contest_id , ROUND((Count(*)*100)/(SELECT count(*) from Users),2)  as percentage
from Users U join Register R 
on U.user_id = R.user_id
group by R.contest_id 
Order by percentage desc,
        R.contest_id 



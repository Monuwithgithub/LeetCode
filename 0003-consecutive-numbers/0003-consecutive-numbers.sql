select distinct num ConsecutiveNums from Logs 
group by num 
having count(num)>3 
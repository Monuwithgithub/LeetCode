select player_id, Min(event_date) as first_login from Activity 
group by player_id 
order by event_date ASC 


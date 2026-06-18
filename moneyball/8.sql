SELECT salary FROM salaries WHERE player_id = (
    SELECT player_id FROM performances ORDER BY HR DESC
) AND year = '2001';

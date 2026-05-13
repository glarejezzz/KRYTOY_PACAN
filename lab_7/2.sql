USE Tour
GO

ALTER TABLE marshrut ADD LastModifiedDate DATETIME DEFAULT GETDATE();
GO

CREATE TRIGGER trg_route_update
ON marshrut
AFTER UPDATE
AS
BEGIN
	UPDATE marshrut
	SET LastModifiedDate = GETDATE()
	WHERE id_route in (SELECT id_route FROM inserted)
	PRINT 'Дата изменения обновлена';

END;
GO;

UPDATE marshrut SET duration_days = 15 WHERE id_route = 1;
GO

SELECT id_route, name_route, duration_days, LastModifiedDate 
FROM marshrut 
WHERE id_route = 1;
GO



--    ▄▄▄▄▄   █  █▀ ▄█ ▄█ ▄███▄     ▄▄▄▄▄   ▄███▄   ██  
--   █     ▀▄ █▄█   ██ ██ █▀   ▀   █     ▀▄ █▀   ▀  █ █ 
-- ▄  ▀▀▀▀▄   █▀▄   ██ ██ ██▄▄   ▄  ▀▀▀▀▄   ██▄▄    █▄▄█
--  ▀▄▄▄▄▀    █  █  ▐█ ▐█ █▄   ▄▀ ▀▄▄▄▄▀    █▄   ▄▀ █  █
--              █    ▐  ▐ ▀███▀             ▀███▀      █
--             ▀                                      █ 
--            
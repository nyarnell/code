(define (map-many l v)
  (if (null? l) v
    (map (car l)
	  (map-many (cdr l) v))))
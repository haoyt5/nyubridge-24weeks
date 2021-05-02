begin
    readln (a, b, c);
    s := (a + b + c)/2.0;
    area := sqrt(s * (s - a)*(s-b)*(s-c));
    writeln(area); 
end
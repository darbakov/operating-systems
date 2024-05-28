void main()
{
    import std.range, std.stdio;

    auto sum = 0.0;
    auto count = stdin
        //Get an input range set up to read one line at a time
        .byLine
        //Perform a transparent operation (as in the shell command tee)
        .tee!(l => sum += l.length)
        .walkLength;

    writeln("Average line length: ",
        count ? sum / count : 0);
}
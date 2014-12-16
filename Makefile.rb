
rule "all", :d => ["ofiles", "tests"]

rule "ofiles", :d => ["strings/bstring.o",
                      "lists/blistd.o",
                      "lists/blists.o",
                      "maps/bhash.o",
                      "func/bfunc.o",
                      "memory/bmem.o"
                     ]

rule "strings/bstring.o", :d => ["strings/bstring.c"] do
    compile :to_obj, :o => "strings/bstring.o"
end

rule "lists/blistd.o", :d => ["lists/blistd.c"] do
    compile :to_obj, :o => "lists/blistd.o"
end

rule "lists/blists.o", :d => ["lists/blists.c"] do
    compile :to_obj, :o => "lists/blists.o"
end

rule "maps/bhash.o", :d => ["maps/bhash.c"] do
    compile :to_obj, :o => "maps/bhash.o"
end

rule "memory/bmem.o", :d => ["memory/bmem.c"] do
    compile :to_obj, :o => "memory/bmem.o"
end

rule "func/bfunc.o", :d => ["func/bfunc.c"] do
    compile :to_obj, :o => "func/bfunc.o"
end

rule "test", :d => ["tests"] do
    shell "./test", :silent
end

rule "tests", :d => ["strings/bstring.o",
                     "lists/blistd.o",
                     "lists/blists.o",
                     "memory/bmem.o",
                     "maps/bhash.o",
                     "test.c"] do
    compile :o => "test"
end

clean "test",
      "func/*.o",
      "lists/*.o",
      "maps/*.o",
      "memory/*.o",
      "strings/*.o"

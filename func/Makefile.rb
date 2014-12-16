
rule "all", :d => ["bfunc.o", "test"]
rule "ofiles", :d => ["bfunc.o", "../lists/blist_double.o"]

rule "bfunc.o", :d => ["../func/bfunc.c"] do
    compile :to_obj, :o => "../func/bfunc.o"
end

rule "../lists/blist_double.o", :d => ["../lists/blist_double.c"] do
    compile :to_obj, :o => "../lists/blist_double.o"
end

rule "test", :d => ["../func/bfunc.o", "../lists/blist_double.o", "test_func.c"] do
    compile :o => "test"
    shell "./test", :silent
end

clean "test",
      "*.o"

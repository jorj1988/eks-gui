RbMake.import_module('../EksCore')
RbMake.import_module('../Eks3D')

if (RbMake.module_exists?(:QtOpenGL))

  RbMake.library(:EksGui, :Eks) do |l, p|
    l.dependencies << :EksCore << :Eks3D << :QtOpenGL
  end 
  
end
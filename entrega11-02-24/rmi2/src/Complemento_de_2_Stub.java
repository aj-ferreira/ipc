// Stub class generated by rmic, do not edit.
// Contents subject to change without notice.

public final class Complemento_de_2_Stub
    extends java.rmi.server.RemoteStub
    implements Int_Complemento_de_2, java.rmi.Remote
{
    private static final long serialVersionUID = 2;
    
    private static java.lang.reflect.Method $method_converte_0;
    
    static {
	try {
	    $method_converte_0 = Int_Complemento_de_2.class.getMethod("converte", new java.lang.Class[] {int.class});
	} catch (java.lang.NoSuchMethodException e) {
	    throw new java.lang.NoSuchMethodError(
		"stub class initialization failed");
	}
    }
    
    // constructors
    public Complemento_de_2_Stub(java.rmi.server.RemoteRef ref) {
	super(ref);
    }
    
    // methods from remote interfaces
    
    // implementation of converte(int)
    public java.lang.String converte(int $param_int_1)
	throws java.rmi.RemoteException
    {
	try {
	    Object $result = ref.invoke(this, $method_converte_0, new java.lang.Object[] {new java.lang.Integer($param_int_1)}, -2998396904022567242L);
	    return ((java.lang.String) $result);
	} catch (java.lang.RuntimeException e) {
	    throw e;
	} catch (java.rmi.RemoteException e) {
	    throw e;
	} catch (java.lang.Exception e) {
	    throw new java.rmi.UnexpectedException("undeclared checked exception", e);
	}
    }
}

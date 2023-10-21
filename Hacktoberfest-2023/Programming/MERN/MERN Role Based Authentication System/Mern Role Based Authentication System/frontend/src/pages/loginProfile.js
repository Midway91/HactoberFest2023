import React from 'react';
import '../css file/login.css';
import NavBar from '../components/NavBar';
import LoginProfile from '../img/loginprofile.png';
import Footer from '../components/Footer';
import { Link } from 'react-router-dom';
import { useState } from 'react';
import { useLogin } from '../hooks/useLogin';
import Col from 'react-bootstrap/Col';
import Form from 'react-bootstrap/Form';
import loginPage from '../img/loginpage.png'

export default function Login() {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [role, setRole] = useState('');
  const { login, error, isLoading } = useLogin();

  const handleSubmit = async (e) => {
    e.preventDefault();
    await login({ email, password, role });
    clearForm();
  };

  function clearForm() {
    setEmail('');
    setRole('');
    setPassword('');
  }

  return (
    <div>
      <NavBar />
      <div className='loginPage'>
        <div className='loginPageLeft'>
          <img src={loginPage} className='loginPageImage'></img>
        </div>
        <div className='loginPageRight'>
          <div className="loginBack">
            <div className="loginS">
              <img src={LoginProfile} alt="signinProfile" className='loginProfileImage'></img>
              <form className='signin' onSubmit={handleSubmit}>
                <h3>Sign In</h3>
                <label>Email</label>
                <input
                  type="email"
                  required
                  onChange={(e) => setEmail(e.target.value)}
                  value={email}
                />
                <label>Password</label>
                <input
                  type="password"
                  required
                  onChange={(e) => setPassword(e.target.value)}
                  value={password}
                />

                <div className="roleDiv">
                  <Form.Group as={Col} controlId="formGridState">
                    <Form.Label>Role</Form.Label>
                    <Form.Select
                      value={role}
                      id='roleInput'
                      onChange={(e) => setRole(e.target.value)}
                    >
                      <option value="" disabled>Select a Role</option>
                      <option value="staff">staff</option>
                      <option value="admin">admin</option>
                      <option value="kitchen">kitchen Staff</option>
                      <option value="pharmacy">pharmacy</option>
                    </Form.Select>
                  </Form.Group>
                </div>
                <div className='loginButton'>
                  <button
                    type="submit"
                    className='submitBtnLogin'
                    disabled={isLoading}
                  >
                    <b>Log in</b>
                  </button>
                </div>
                <div className="change-password-link">
                    <Link to="/changePassword">Change Password ?</Link>
                </div>
                {error && <div className='errorLogin'>{error}</div>}
              </form>
            </div>
          </div>
        </div>     
      </div>

      <Footer />
    </div>
  );
}

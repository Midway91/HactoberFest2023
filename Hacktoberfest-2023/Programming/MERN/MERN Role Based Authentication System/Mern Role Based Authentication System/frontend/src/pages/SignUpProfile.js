import React from 'react'
import '../css file/signup.css';
import NavBar from '../components/NavBar';
import LoginProfile from '../img/loginprofile.png';
import SignUpImage from '../img/signuppage.png'
import Footer from '../components/Footer';
import { Link } from 'react-router-dom';
import { useState } from 'react';
import { useSignup } from '../hooks/useSignup';
import Button from 'react-bootstrap/Button';
import Col from 'react-bootstrap/Col';
import Form from 'react-bootstrap/Form';
import Row from 'react-bootstrap/Row';


export default function Signup() {
  const [email, setEmail] = useState('')
  const [password, setPassword] = useState('')
  const [role, setRole] = useState('')
  const { signup, error, isLoading } = useSignup()

  const handleSubmit = async (e) => {
    e.preventDefault()
    console.log(email, password, role);
    await signup({ email, password, role });
    clearForm();
  }
  function clearForm() {
    setEmail("");
    setRole("");
    setPassword("");
  }
  return (
    <div>
      <NavBar />
      <div className='signUpPage'>
        <div className='signUpPageLeft'>
          <img src= {SignUpImage} className='signUpPageImage'></img>
        </div>
        <div className='signUpPageRight'>
          <div className="signupBack">
            <div className="signupS">
              <img src={LoginProfile} className='loginProfileImage'></img>
              <form className='signup' onSubmit={handleSubmit}>
                <h3>Sign Up</h3>
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
                    <Form.Select value={role} id='roleInput' onChange={(e) => setRole(e.target.value)}>
                      <option value="" disabled>Select a Role</option>
                      <option value="staff">staff</option>
                      <option value="admin">admin</option>
                      <option value="kitchen">kitchen Staff</option>
                      <option value="pharmacy">pharmacy</option>
                    </Form.Select>
                  </Form.Group>
                </div>

                <button type="submit" onClick={handleSubmit} className='submitBtnSignup' disabled={isLoading}><b>Sign Up</b></button>
                {error && <div className='errorSignup'>{error}</div>}
              </form>
            </div>
          </div>
        </div>
      </div>

      <Footer />
    </div>
  )
}
